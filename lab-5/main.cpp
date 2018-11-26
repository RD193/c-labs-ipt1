#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main()
{
  FILE * inpf = fopen("test.in.txt" , "r");
  FILE * optf = fopen("test.out.txt" , "w");
  char str [256];
  char H [] = "Hello";
  char h [] = "hello";
  if (inpf == NULL) perror("Ошибка открытия файла");
  else
  {
    while ( fgets(str, 256, inpf) != NULL )
    {
      //puts(str);
      char raw_str [256];
      strcpy(raw_str, str);
      char * pch = strtok (str," ,.-&\n");
      while (pch != NULL)
      {
        if((strcmp(pch, "Hello") == 0) || (strcmp(pch, "hello") == 0)) 
        {
          fputs(raw_str, optf);
          break;
        }
        pch = strtok (NULL, " ,.-");
      }
    }
    fclose (inpf);
  }
  return 0;
}