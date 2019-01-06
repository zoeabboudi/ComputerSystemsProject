    //print html to browser                                                                                      
    sprintf(content,"<html><body style='background-color:#AED6F1;'><style>h1{color:#1B4F72}h2{color:#196F3D}</st\
yle><center><h1>Your Weather</h1><h2> brought to you by <strong>Mori and Zoe</strong></h2><img align='middle' sr\
c='sunny.jpg'><h1>Enter Your zipcode: %s</h1><form action='/cgi-bin/SemesterProject?'><input type='text' name='z\
ipcode'><br><input type='submit' value='Submit'></form><h2>the temperature outside:</h2><h1>%s</h1></center></bo\
dy></html>",  zipcode, temp);

    /* Generate the HTTP response */
    printf("Connection: close\r\n");
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);

    exit(0);
}                                                                                                                 









                                                                                                                  



