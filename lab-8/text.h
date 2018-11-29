#include <string>
#include <iostream>
#include <fstream>
using namespace std;
struct line
{
  string str;
  line *next;
};
line* Inp(const char* inp);
void past(line* ln);
int Count(line* ln);
void change_letter(line* ln);
void swap_lines(line* raw_ln);
void change_line(line* raw_ln);
