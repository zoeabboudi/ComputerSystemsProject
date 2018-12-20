#include "csapp.h"

int main(void)
{
  
  char *str = "{\"status\":\"ok","totalResults\":2510,\"articles\":[{\"source\":{\"id\":null,\"name\":\"Lifehacker.com\"},\"author\":\"David Murphy\",\"title\":\"How to Keep Apple From Spamming Your Phone\",\"description\":\"What\u2019s worse than Carpool Karaoke? Getting Carpool Karaoke notifications on your iPhone when you haven\u2019t watched it in a long, long time. Read more...";
  //int i;
  char *index = strstr(str, "title");
  printf("heres the index %s", index);
     
}
