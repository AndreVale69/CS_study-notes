import java.util.Random;
import java.util.Scanner;

/*
 * Si scriva un programma che legge da tastiera un long non negativo n e lo richiede a oltranza se
 * l'utente lo inserisse negativo.
 * Quindi genera n coppie (x,y) fatte da due numeri casuali di tipo double, fra -1 e 1.
 * Per ogni coppia controlla se la coordinata (x,y) sta dentro il cerchio di raggio 1 centrato
 * sull'origine degli assi e in tal caso incrementa una variabile dentro di tipo long.
 * Alla fine stampa il valore della formula dentro * 4 / n senza perdere le cifre che seguono la virgola.
 */

public class FirstExercise {
    public static void main(String[] args){
        // Declaration var to read input
        Scanner keyboard = new Scanner(System.in);

        // Declaration coordinates
        double cp1, cp2;

        // Number of comparing
        int n;

        // Create obj random
        Random random = new Random();

        // Create counter
        double inside = 0;

        // Control the value of n
        do {
            System.out.println("Insert positive value: ");
            n = keyboard.nextInt();
            if (n < 0)
                System.out.println("Error value");
        } while(n < 0);

        for (int j = 0; j < n; j ++){
            // Generate random numbers (range +1 and -1)
            cp1 = (random.nextDouble() * 2) -1;
            cp2 = (random.nextDouble() * 2) -1;

            // Calculate distance from the origin
            //sqrt(x_2 - x_1)^2 + (y_2 - y_1)^2
            double distance = Math.sqrt(Math.pow(cp1, 2) + Math.pow(cp2, 2));
            if (distance <= 1)
                inside ++;
        }

        // Print result
        System.out.println(inside * 4.0 / n);
        keyboard.close();
    }
}
