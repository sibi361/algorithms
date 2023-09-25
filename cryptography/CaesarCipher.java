class Caesar {
    static String convert(String input, int offset) {
        StringBuffer str = new StringBuffer(input);
        char temp, newChar;
        newChar = 0;

        for (int i = 0; i < str.length(); i++) {
            temp = str.charAt(i);

            if (temp == ' ')
                continue;
            else {
                if (temp >= 97 && temp <= 122)
                    newChar = (char) (97 + (temp - 97 + offset) % 26);
                else if (temp >= 65 && temp <= 90)
                    newChar = (char) (65 + (temp - 65 + offset) % 26);
                str.setCharAt(i, newChar);
            }
        }
        return str.toString();
    }

    static String convertLowercaseOnly(String input, int offset)
            throws CaesarCipherOnlyLowercaseSupported {
        StringBuffer str = new StringBuffer(input);
        char temp, newChar;

        for (int i = 0; i < str.length(); i++) {
            temp = str.charAt(i);

            if ((temp < 97 || temp > 122) && temp != ' ')
                throw new CaesarCipherOnlyLowercaseSupported();
            else if (temp == ' ')
                continue;

            newChar = (char) (97 + (temp - 97 + offset) % 26);
            str.setCharAt(i, newChar);
        }
        return str.toString();
    }
}

class CaesarCipherOnlyLowercaseSupported extends Exception {
    public String toString() {
        return "CaesarCipherOnlyLowercaseSupported Exception: Input string " +
                "contains invalid characters\nconvertLowercaseOnly() " +
                "accepts only lowercase characters and spaces\n";
    }
}

class CaesarCipher {
    public static void main(String[] args) {
        String sample_input_lowercase = "abcdefghijklm nopqrstuvwxyz";
        String sample_input = "abcdefghijklm NOPQRSTUVWXYZ";
        int offset;

        String output = "";
        offset = 10;
        // offset = 26; // same string
        // offset = 31; // same as offset 5

        System.out.println("Given offset: " + offset);

        try {
            output = Caesar.convertLowercaseOnly(sample_input_lowercase, offset);
            System.out.println("\nconvertLowercaseOnly(): " + output);
        } catch (CaesarCipherOnlyLowercaseSupported e) {
            System.out.println(e);
        }

        System.out.println("\nconvertLowercaseOnly() but uppercase given: ");
        try {
            output = Caesar.convertLowercaseOnly(sample_input, offset);
            System.out.println("\nOutput lowercase only but uppercase given: " + output);
        } catch (CaesarCipherOnlyLowercaseSupported e) {
            System.out.println(e);
        }

        output = Caesar.convert(sample_input, offset);
        System.out.println("convert(): " + output + "\n");
    }
}
