# Lab 7: BMI and Color Mixer

**Name:** TRISHI SINGH  
**Course section:** CIS-165-W099

This repository contains two independent C++17 programs: `bmi.cpp` and `color_mixer.cpp`.

## 1. Program plans

### Program 1: Body Mass Index (`bmi.cpp`)

**Inputs:** Weight in pounds and height in inches, both stored as `double`.

**Variables:** `weight` stores the weight, `height` stores the height, `bmi` stores the calculation, and `category` stores the BMI classification.

**Plan:**

1. Ask the user for weight and height.
2. Check that both values are greater than zero. If either is zero or negative, display an error and end before calculating BMI.
3. Calculate and store `weight * 703.0 / (height * height)` in `bmi`.
4. Classify using the unrounded BMI:
   - Less than 18.5: Underweight
   - 18.5 through 25.0, including both endpoints: Optimal weight
   - Greater than 25.0: Overweight
5. Display the BMI using `fixed` and `setprecision(2)`, followed by its category.

### Program 2: Color Mixer (`color_mixer.cpp`)

**Inputs:** Two lowercase primary-color names: red, blue, or yellow.

**Variables and tools:** `COLOR_SIZE` is a named constant for the character-array size. `first_color` and `second_color` store the inputs in character arrays. `strcmp` from `<cstring>` compares the strings, and `setw` from `<iomanip>` limits input length so there is room for the ending null character.

**Plan:**

1. Read both color names into bounded character arrays using `setw(COLOR_SIZE)`.
2. Check that both inputs are valid primary colors.
3. If either input is invalid, display an error message.
4. If both valid inputs are the same, display that primary color.
5. If the colors differ, check both input orders and display the mixture: red + blue = purple; red + yellow = orange; blue + yellow = green.

## 2. Compile and run instructions

The programs were written in C++17 using OnlineGDB.

1. Open OnlineGDB.
2. Select C++17.
3. Create two separate programs, `bmi.cpp` and `color_mixer.cpp`.
4. Enter the program.
5. Click Run.
6. Enter various choices and run.
7. Ensure the output values are accurate to the expected results.

## 3. Testing

### Program 1: BMI

**Test 1**

- Input: `100, 70`
- Expected result: 14.35 — underweight
- Actual result: 14.35 — underweight
- Result: Pass

**Test 2**

- Input: `150, 70`
- Expected result: 21.52 — optimal weight
- Actual result: 21.52 — optimal weight
- Result: Pass

**Test 3**

- Input: `200, 70`
- Expected result: 28.69 — overweight
- Actual result: 28.69 — overweight
- Result: Pass

**Test 4**

- Input: `150, 0`
- Expected result: Error: weight and height must be positive.
- Actual result: Error: weight and height must be positive.
- Result: Pass

**Test 5**

- Input: `-150, 79`
- Expected result: Error: weight and height must be positive.
- Actual result: Error: weight and height must be positive.
- Result: Pass

**Additional test**

- Input: `-120, -70`
- Expected result: Error: weight and height must be positive.
- Actual result: Error: weight and height must be positive.
- Result: Pass
- Purpose: Check whether two negative numbers would also produce an error.

### Program 2: Color Mixer

**Test 1**

- Input: `red, blue`
- Expected result: purple
- Actual result: purple
- Result: Pass

**Test 2**

- Input: `red, yellow`
- Expected result: orange
- Actual result: orange
- Result: Pass

**Test 3**

- Input: `blue, yellow`
- Expected result: green
- Actual result: green
- Result: Pass

**Test 4**

- Input: `blue, red`
- Expected result: purple
- Actual result: purple
- Result: Pass

**Test 5**

- Input: `red, red`
- Expected result: red
- Actual result: red
- Result: Pass

**Test 6**

- Input: `orange, blue`
- Expected result: Error: enter red, blue, or yellow.
- Actual result: Error: enter red, blue, or yellow.
- Result: Pass

**Test 7**

- Input: `orange, red`
- Expected result: Error: enter red, blue, or yellow.
- Actual result: Error: enter red, blue, or yellow.
- Result: Pass

**Additional test**

- Input: `pink, blue`
- Expected result: Error: enter red, blue, or yellow.
- Actual result: Error: enter red, blue, or yellow.
- Result: Pass
- Purpose: Check whether any other colors were accepted.

## 4. Explain your code

### 1. How does the BMI formula use pounds and inches? Why is `height * height` needed?

The program uses `weight * 703.0 / (height * height)`. Weight is entered in pounds and height in inches. Multiplying height by itself squares the height, as required by the formula.

### 2. How do your conditions handle exactly 18.5 and exactly 25.0? Does the order of your conditions matter?

The program first checks whether BMI is below 18.5. It then checks whether BMI is less than or equal to 25.0. Any remaining value is greater than 25.0. This includes both endpoints in the Optimal weight category without leaving gaps.

### 3. Why do you check weight and height before calculating BMI?

Both values must be greater than zero. Checking them first prevents calculation with zero or negative input and displays the required error before the calculation.

### 4. Why do you classify the unrounded BMI and round only its displayed value?

The unrounded BMI is used to choose the category. Rounding first could change a value near a boundary. `fixed` and `setprecision(2)` format only the displayed value to two decimal places.

### 5. What does `strcmp` return for equal text? Why is `==` not the correct comparison for character-array contents?

`strcmp` returns 0 when two character strings contain the same text. `==` does not compare the contents of two character arrays as strings, so `strcmp` is used.

### 6. How do you make each mixture work in either input order and handle two identical primary colors?

The program checks both possible orders for each different pair. It also checks whether both valid inputs are identical; if they are, it displays that primary color.

### 7. How do you check for an invalid color in either input position?

Each input is compared with all three valid names using `strcmp`. If either input is not red, blue, or yellow, the program displays an error instead of a mixed color.

### 8. How do named constants and result variables make your programs easier to read and check?

The named constant `COLOR_SIZE` makes the character-array size clear and easier to maintain. Result variables store calculations or selected results before output, making the programs easier to read and check.
