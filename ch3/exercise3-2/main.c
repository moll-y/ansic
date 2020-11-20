#include <stdio.h>

void escape (char source[], char target[]);
void unescape (char source[], const char target[]);

int
main ()
{
  char t[] = "\n\tkoto\n\t";
  char s[20];

  escape (s, t);
  printf ("%s\n", s);

  unescape (t, s);
  printf ("%s\n", t);

  return 0;
}

void
escape (char s[], char t[])
{
  int i, j;

  for (i = j = 0; t[i] != '\0'; ++i)
    {
      switch (t[i])
	{
	case '\n':
	  s[j++] = '\\';
	  s[j++] = 'n';
	  break;
	case '\t':
	  s[j++] = '\\';
	  s[j++] = 't';
	  break;
	default:
	  s[j++] = t[i];
	  break;
	}
    }
  s[j] = '\0';
}

void
unescape (char s[], const char t[])
{
  int i, j;

  for (i = j = 0; t[i] != '\0'; ++i)
    {
      if (t[i] == '\\')
	{
	  switch (t[++i])
	    {
	    case 'n':
	      s[j++] = '\n';
	      break;
	    case 't':
	      s[j++] = '\t';
	      break;
	    default:
	      s[j++] = '\\';
	      --i;
	      break;
	    }
	}
      else
	{
	  s[j++] = t[i];
	}
    }
  s[j] = '\0';
}
