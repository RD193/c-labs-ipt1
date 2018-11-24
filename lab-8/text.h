#include <string>
#include <iostream>
#include <fstream>
using namespace std;
struct line
{
  string str;
  line *next;
};
line* Inp();
void past(line* ln);
int Count(line* ln);
void change_letter(line*& ln, int line_number, int letter_number, char c);
void swap_lines(line*& raw_ln, int i_line_num, int j_line_num);
void change_line(line*& raw_ln, int i_line_num, int j_line_num);
