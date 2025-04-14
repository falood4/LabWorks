import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
public class file {
	public static void main(String[] args) { 
	String inputFilePath = "C:\\Users\\student\\Documents\\oot lab\\file samples\\input.txt"; 
	String outputFilePath = "C:\\Users\\student\\Documents\\oot lab\\file samples\\output.txt";
	try {
		BufferedReader reader = new BufferedReader(new FileReader(inputFilePath));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outputFilePath));
		String line;
		while ((line = reader.readLine()) != null) {
		String modifiedLine = line.replace(" ", "_");
		writer.write(modifiedLine);
		writer.newLine();
		}
		
		writer.close();
		reader.close();
		
		System.out.println("File copied");
	}
	catch(IOException e){
		System.out.println("an error occured:" + e.getMessage());
	}
	}
}
