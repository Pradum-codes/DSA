import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class SolutionSaver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter LeetCode Problem Number: ");
        int problemNumber = sc.nextInt();
        sc.nextLine(); // consume newline

        System.out.println("Paste your solution below (type 'END' in a new line to finish):");
        StringBuilder solutionContent = new StringBuilder();
        String line;

        while (!(line = sc.nextLine()).equals("END")) {
            solutionContent.append(line).append("\n");
        }

        String fileName = problemNumber + ".java.txt";
        String header = "This is a Java file for LeetCode Problem: " + problemNumber + "\n" + "Change the file Name to main to run"+"\n";

        try (FileWriter writer = new FileWriter(fileName)) {
            writer.write(header);
            writer.write(solutionContent.toString());
            System.out.println("✅ Solution saved to " + fileName);
        } catch (IOException e) {
            System.out.println("❌ Error writing to file: " + e.getMessage());
        }

        sc.close();
    }
}
