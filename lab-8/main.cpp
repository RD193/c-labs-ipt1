#include "text.h"

int main() {
  line* test_text = Inp("input.txt");
  change_letter(test_text, 1, 2, 'a');
  swap_lines(test_text, 1, 2);
  past(test_text);
  change_line(test_text, 1, 2);
  past(test_text);
  cout << Count(test_text);
}
