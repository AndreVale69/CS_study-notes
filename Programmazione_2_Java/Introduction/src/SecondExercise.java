/*
 * Si scriva un programma Java che legge un intero non negativo n da tastiera e stampa una cornice n x n:
@@@@@@
@    @
@    @
@    @
@    @
@@@@@@

 */

import java.util.Scanner;

public class SecondExercise {
    public static void main(String[] args){
        // Create obj to read input
        Scanner keyboard = new Scanner(System.in);

        // Create var to read dimension of frame
        int n;

        // Control value
        do {
            System.out.print("Insert a positive integer: ");
            n = keyboard.nextInt();
            if (n < 0)
                System.out.println("Error!");
        } while (n < 0);

        // Print frame
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                if(i == 0 || i + 1 == n)
                    System.out.print("@");
                else
                    if(j == 0 || j + 1 == n)
                        System.out.print("@");
                    else
                        System.out.print(" ");
            }
            System.out.print("\n");
        }
    }
}
