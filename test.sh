#!/bin/bash

# Check if the compiled program 'rpn4' exists and is executable
PROGRAM="./rpn4"
if [[ ! -x "$PROGRAM" ]]; then
  echo "Error: Program '$PROGRAM' does not exist or is not executable."
  exit 1
fi

# Initialize log file
LOG_FILE="log.txt"
echo "Test Report" > $LOG_FILE
echo "------------------" >> $LOG_FILE

# Read the unit tests from unit_tests.txt
while IFS=":" read -r inputs expected_output; do
  # Prepare the input string to pass to the program
  input_args=$(echo "$inputs" | tr ' ' ' ')

  # Run the program and capture its output
  output=$($PROGRAM $input_args)

  # Extract only the numeric part of the output (ignoring any extra text like "RESULT :")
  # Use grep to search for numeric values, including negatives or the word "ERROR"
  numeric_output=$(echo "$output" | grep -Eo '([+-]*[0-9]+|ERROR)')
  # Compare the extracted numeric output with the expected output
  if [[ "$numeric_output" == "$expected_output" ]]; then
    result="Success"
  else
    result="Failure (Expected: $expected_output, Got: $output)"
  fi

  # Print and log the result
  echo "Test: Inputs: $inputs Expected Output: $expected_output => Actual Output: $numeric_output => $result"
  echo "Test: Inputs: $inputs Expected Output: $expected_output => Actual Output: $numeric_output => $result" >> $LOG_FILE

done < unit_tests.txt

# Display the summary report
echo "------------------"
echo "Test report saved to $LOG_FILE"
