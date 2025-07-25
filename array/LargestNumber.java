public class LargestNumber {
    public static void main(String[] args) {
        // Hard-coded array of numbers
        int[] numbers = {23, 45, 67, 12, 89, 34};

        // Variable to hold the largest number
        int largest = numbers[0];

        // Loop through the array
        for (int i = 1; i < numbers.length; i++) {
            if (numbers[i] > largest) {
                largest = numbers[i]; // Update largest number
            }
        }

        // Output the largest number
        System.out.println("The largest number in the array is: " + largest);
    }
}
