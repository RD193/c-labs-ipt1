#include "text.h"

int main() {
  line* test_text, *test_text_f;
  test_text = test_text_f = Inp("input.txt");
  cout << "text used for test";
  past(test_text);
  int pnt;
  cout << "1 for chage letter\n2 for swap strings\n3 for change text of one string to text from other string\n4 to see number of strings\n5 to past text\n";
  while(true)
  {
    cin >> pnt;
    switch(pnt)
    {
      case 1:
        change_letter(test_text);
        break;
      case 2:
          swap_lines(test_text);
          break;
      case 3:
        change_line(test_text);
        break;
      case 4:
        cout << Count(test_text);
        break;
      case 5:
        past(test_text);
        break;  
    }
    past(test_text);
  }
}
