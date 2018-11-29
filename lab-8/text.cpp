#include "text.h"
line* Inp(const char* inp)
{
  line *current, *first;
  FILE * inpf = fopen("input.txt" , "r");
  string inp_str;
  char str [256];
  current = first = new line;
  while (fgets(str, 256, inpf) != NULL)
  {    
    inp_str = str;
    current->str = inp_str;
    current->next = new line;
    current = current->next;
  }
  current->next = NULL;
  return first;
}
void past(line* ln)
{
  cout << "Actual text:" << endl;
  cout << ln->str;
  while(ln->next != NULL)
  {
    ln = ln->next;
    cout << ln->str;
  }
  cout << endl;
  return;
}
int Count(line* ln)
{
  cout << "numer of lines: ";
  int answer = 0;
  while(ln->next != NULL)
  {
    ln = ln->next;
    answer++;
  }
  return answer;
}
void change_letter(line* ln)
{
  int line_number, letter_number;
  char c;
  cout <<"Write numer of string(first is 1) and numver of letter(first is 1)\n";
  cin >> line_number;
  cin >> letter_number;
  cout <<"New letter:\n";
  cin >> c;
  for(int i = 0; i < line_number-1; i++)
  {
    if(ln->next == NULL & (line_number - i>1))
    {
      cout << "No such line" << endl;
      break;
    }
    cout <<"line:"<< ln->str << endl;
    ln = ln->next;
  }
  ln->str[letter_number - 1] = c;
}
void swap_lines(line* raw_ln)
{
  int i_line_num, j_line_num;
  cout <<"Write numer of fist and second string(first is 1)\n";
  cin >> i_line_num;
  cin >> j_line_num;
  string temp;
  line *i_line, *j_line;
  int i = 1, n = 0;
  line* ln = raw_ln;
  if(i_line_num - 1 == 0)
    {
      i_line = ln;
      n++;
    }
  if(j_line_num - 1 == 0)
  {
    j_line = ln;
    n++;
  }
  while(ln->next != NULL)
  {
    ln = ln->next;
    if(i == i_line_num - 1)
    {
      i_line = ln;
      n++;
    }
    if(i == j_line_num - 1)
    {
      j_line = ln;
      n++;
    }
    if(n==2){break;}
    i++;
  }
  if(n!=2)
  {
  cout << "No such lines";
  return;
  }
  temp = i_line->str;
  i_line->str = j_line->str;
  j_line->str = temp;
}
void change_line(line* raw_ln)
{
  int i_line_num, j_line_num;
  cout <<"Write numer of fist and second string(first is 1)\n";
  cin >> i_line_num;
  cin >> j_line_num;
  line *i_line, *j_line;
  int i = 1, n = 0;
  line* ln = raw_ln;
  if(i_line_num - 1 == 0)
    {
      i_line = ln;
      n++;
    }
  if(j_line_num - 1 == 0)
  {
    j_line = ln;
    n++;
  }
  while(ln->next != NULL)
  {
    ln = ln->next;
    if(i == i_line_num - 1)
    {
      i_line = ln;
      n++;
    }
    if(i == j_line_num - 1)
    {
      j_line = ln;
      n++;
    }
    if(n==2){break;}
    i++;
  }
  if(n!=2)
  {
  cout << "No such lines";
  return;
  }
  i_line->str = j_line->str;
}
