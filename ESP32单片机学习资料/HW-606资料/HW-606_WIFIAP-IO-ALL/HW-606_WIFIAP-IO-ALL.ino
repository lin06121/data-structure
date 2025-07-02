#include <WiFi.h>

// WIFI名称及密码
const char* ssid = "ESP32-HW";
const char* password = "";

// 将 Web 服务器端口号设置为 80
WiFiServer server(80);

// 用于存储 HTTP 请求的变量
String header;

// 辅助变量存储当前输出状态
// String output26State = "off";
String output13State = "off";


int led_io[36]={0,1,2,3,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};

// 将输出变量分配给 GPIO 引脚
// const int output26 = 26;
const int output13 = 13;

// 当前时间
unsigned long currentTime = millis();
// 前一时刻
unsigned long previousTime = 0; 
// 定义超时时间（以毫秒为单位）（示例：2000ms = 2s）
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  pinMode(19,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
    pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);
  // 将输出变量初始化为输出
  // pinMode(output26, OUTPUT);
  pinMode(output13, OUTPUT);
  // 将输出设置为低电平
  // digitalWrite(output26, LOW);
  digitalWrite(output13, LOW);

  // 使用 SSID 和密码连接到 Wi-Fi 网络
  // Serial.print("Connecting to ");
  // Serial.println(ssid);
  // WiFi.begin(ssid, password);
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   Serial.print(".");
  // }
  // // 打印本地IP地址并启动Web服务器
  // Serial.println("");
  // Serial.println("WiFi connected.");
  // Serial.println("IP address: ");
  // Serial.println(WiFi.localIP());
  // server.begin();


   if (!WiFi.softAP(ssid, password)) {
    log_e("Soft AP creation failed.");
    while(1);
  }
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
}

void loop(){
  WiFiClient client = server.available();   // 监听数据

  if (client) {                             // 如果有新客户端连接，
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // 在串行端口中打印一条消息
    String currentLine = "";                // 创建一个字符串来保存来自客户端的传入数据
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // 当客户端连接时循环
      currentTime = millis();
      if (client.available()) {             // 如果有字节要从客户端读取，
        char c = client.read();             // 读取一个字节
        Serial.write(c);                    // 将其打印出串行监视器
        header += c;
        if (c == '\n') {                    // 如果该字节是换行符
           // 如果当前行为空，则连续有两个换行符。
           // 这就是客户端 HTTP 请求的结束，因此发送响应：
          if (currentLine.length() == 0) {
             // HTTP 标头始终以响应代码开头（例如 HTTP/1.1 200 OK）
             // 一个内容类型，以便客户端知道接下来会发生什么，然后是一个空行：
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // 打开和关闭 GPIO
            // if (header.indexOf("GET /26/on") >= 0) {
            //   Serial.println("GPIO 26 on");
            //   output26State = "on";
            //   digitalWrite(output26, HIGH);
            // } else if (header.indexOf("GET /26/off") >= 0) {
            //   Serial.println("GPIO 26 off");
            //   output26State = "off";
            //   digitalWrite(output26, LOW);
            // } else 
            if (header.indexOf("GET /on") >= 0) {
              Serial.println("GPIO on");
              output13State = "on";
              digitalWrite(output13, HIGH);
              int i;
              for(i=0;i<35;i++)//当按钮控制8引脚上拉时，其他引脚跟随
              { digitalWrite(led_io[i],HIGH);}

            } else if (header.indexOf("GET /off") >= 0) {
              Serial.println("GPIO off");
              output13State = "off";
              digitalWrite(output13, LOW);
              int i;
              for(i=0;i<35;i++)//当按钮控制8引脚下拉时，其他引脚跟随
              {digitalWrite(led_io[i],LOW);}
              
            }
            
            // 显示 HTML 网页
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
             // CSS 设置开/关按钮的样式
             // 随意更改背景颜色和字体大小属性以满足您的喜好
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // 网页标题
            client.println("<body><h1>ESP32 HW-606</h1>");
            
            // 显示 GPIO 26 的当前状态和 ON/OFF 按钮
            // client.println("<p>GPIO 26 - State " + output26State + "</p>");
            // // 如果output26状态为off，则显示ON按钮      
            // if (output26State=="off") {
            //   client.println("<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>");
            // } else {
            //   client.println("<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>");
            // } 
               
            // 显示 GPIO 13 的当前状态和 ON/OFF 按钮
            client.println("<p>GPIO  - State " + output13State + "</p>");
            // 如果output8状态为off，则显示ON按钮     
            if (output13State=="off") {
              client.println("<p><a href=\"/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");
            
            // HTTP 响应以另一个空行结束
            client.println();
            // 跳出 while 循环
            break;
          } else { // 如果有换行符，则清除 currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // 如果除了回车符之外还有其他字符，
          currentLine += c;      // 将其添加到当前行的末尾
        }
      }
    }
    // 清除头变量
    header = "";
    // 关闭连接
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
