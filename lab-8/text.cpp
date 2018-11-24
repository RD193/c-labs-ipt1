#include "text.h"
line* Inp()
{
  line *current, *first;
  ifstream cin("input.txt");
  string inp_str;
  current = first = new line;
  getline(cin,inp_str);
  if (inp_str != "#")
  {
      current->str = inp_str;
  }
  while (inp_str != "#")
  {
    current->next = new line;
    current = current->next;    
    current->str = inp_str;
    getline(cin,inp_str);
  }
  current->next = NULL;
  cin.close();
  return first;
}
void past(line* ln)
{
  cout << "Actual text:" << endl;
  cout << ln->str << endl;
  while(ln->next != NULL)
  {
    ln = ln->next;
    cout << ln->str << endl;
  }
  return;
}
int Count(line* ln)
{
  cout << "numer of lines: ";
  int answer = 0;
  if(ln->str == "")
  {
    return 0;
  }
  while(ln->next != NULL)
  {
    ln = ln->next;
    answer++;
  }
  return answer;
}
void change_letter(line*& ln, int line_number, int letter_number, char c)
{
  for(int i = 0; i < line_number; i++)
  {
    if(ln->next == NULL)
    {
      cout << "No such line" << endl;
      break;
    }
    ln = ln->next;
  }
  ln->str[letter_number - 1] = c;
}
void swap_lines(line*& raw_ln, int i_line_num, int j_line_num)
{
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
void change_line(line*& raw_ln, int i_line_num, int j_line_num)
{
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