import java.io.*;
import java.util.*;

class Question implements Serializable {
    private static final long serialVersionUID = 1L;
    private String question;
    private Boolean answer;

    public Question(String question, Boolean answer) {
        this.question = question;
        this.answer = answer;
    }

    public String getQuestion() { return question; }
    public Boolean getAnswer() { return answer; }
}

class QuestionBankCreator {
    public static void create() {
        Scanner scanner = new Scanner(System.in);
        List<Question> questionBank = new ArrayList<>();

        System.out.print("How many questions? ");
        int n = Integer.parseInt(scanner.nextLine().trim());

        for (int i = 1; i <= n; i++) {
            System.out.print("Question " + i + ": ");
            String questionText = scanner.nextLine();

            Boolean answer = null;
            while (answer == null) {
                System.out.print("Answer (true/false): ");
                String ans = scanner.nextLine().trim().toLowerCase();
                if (ans.equals("true")) answer = true;
                else if (ans.equals("false")) answer = false;
                else System.out.println("Enter true or false only.");
            }

            questionBank.add(new Question(questionText, answer));
        }

        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("questionbank.ser"))) {
            oos.writeObject(questionBank);
            System.out.println("Saved successfully.");
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}

class TakeTest {
    public static void take() {
        List<Question> questionBank = new ArrayList<>();

        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("questionbank.ser"))) {
            questionBank = (List<Question>) ois.readObject();
        } catch (FileNotFoundException e) {
            System.out.println("File not found. Create question bank first.");
            return;
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
            return;
        }

        Scanner scanner = new Scanner(System.in);
        int score = 0;
        List<Boolean> userAnswers = new ArrayList<>();

        for (int i = 0; i < questionBank.size(); i++) {
            Question q = questionBank.get(i);
            System.out.print("Q" + (i + 1) + ": " + q.getQuestion() + "\nAnswer (true/false): ");

            Boolean userAnswer = null;
            while (userAnswer == null) {
                String input = scanner.nextLine().trim().toLowerCase();
                if (input.equals("true")) userAnswer = true;
                else if (input.equals("false")) userAnswer = false;
                else System.out.print("Enter true or false only: ");
            }

            userAnswers.add(userAnswer);
            if (userAnswer.equals(q.getAnswer())) score++;
        }

        System.out.println("\nScore: " + score + "/" + questionBank.size());

        for (int i = 0; i < questionBank.size(); i++) {
            Question q = questionBank.get(i);
            boolean correct = userAnswers.get(i).equals(q.getAnswer());
            System.out.println("\nQ" + (i + 1) + ": " + q.getQuestion());
            System.out.println("Correct: " + q.getAnswer() + " | Yours: " + userAnswers.get(i) + " | " + (correct ? "Right" : "Wrong"));
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("1. Create Question Bank");
        System.out.println("2. Take Test");
        System.out.print("Choice: ");
        int choice = Integer.parseInt(scanner.nextLine().trim());

        if (choice == 1) QuestionBankCreator.create();
        else if (choice == 2) TakeTest.take();
        else System.out.println("Invalid choice.");
    }
}


/*


for(int i=0 to i < s.length())
{
if(s[i].matches("[A-Z]"))
{
s[i].tolowerCase();
}
else{
s[i].toupperCase();
}
}
*/