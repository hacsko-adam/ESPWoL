#ifndef DISPLAY_H
#define DISPLAY_H

#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

class WolWebserver
{
private:
    void handleRoot()
    {
        String body = "<!DOCTYPE html>"
                      "<html>"
                      "<head>"
                      "<title>TaDev remote</title>"
                      "<meta charset='utf-8' />"
                      "<style>body{background:#34495e;color:#fff;text-align:center;font-family:Helvetica,Arial,sans-serif;font-size:10pt}h1{font-size:3em}form{width:500px;margin:0 auto;background:#fff;border-radius:10px;margin-bottom:20px}.floating-placeholder,input{font-family:Helvetica,Arial,sans-serif;font-size:20pt;line-height:2.6em;height:2.6em;margin:0;padding:0;width:100%}.floating-placeholder input:focus+label{color:#16abf0}.floating-placeholder input[value]+label{color:red}.floating-placeholder{position:relative}.floating-placeholder input{font-size:20pt;border:none;outline:0;position:absolute;top:0;left:0;display:block;background:0 0;z-index:2;border-bottom:1px solid #ccc;text-indent:20px}.floating-placeholder:last-child input{border-bottom:none}.floating-placeholder-float input{line-height:3.4em}</style>"
                      "</head>"
                      "<body>"
                      "<h1>Ta-Dev Counter</h1>"
                      "<h2>Mennyit mutasson a számláló?</h2>"
                      "<form method='get' action='set'>"
                      "<div class='floating-placeholder'>"
                      "<input name='number' type='number' placeholder='";
        body += "'/>"
                "</div>"
                "<div class='floating-placeholder'>"
                "<input id='kuldes' name='address' type='submit' value='Küldjed!' />"
                "</div>"
                "</form>"
                "<span><u>by Adam Hacsko</u></span> "
                "</body>"
                "</html>";

        server.send(200, "text/html", body);
    }

public:
    WolWebserver()
    {
        server.on("/", handleRoot);
    }

    void handleClient()
    {
        server.handleClient();
    }
};

#endif