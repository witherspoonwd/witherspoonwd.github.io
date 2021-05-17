#include <iostream>
#include <fstream>

using namespace std;

int main() {

  string blogtextFN, outputFN, dateText;
  cout << "Enter blogtext filename: ";
  getline(cin, blogtextFN);

  cout << "Enter output filename (include extension): ";
  getline(cin, outputFN);

  cout << "Enter date text: ";
  getline(cin, dateText);

  ifstream blogText;
  ifstream htmlTemplate;
  ofstream blogHtml;

  blogText.open (blogtextFN);
  htmlTemplate.open ("blogtemplate.html");
  blogHtml.open (outputFN);

  string copyLine, skipLine;

  getline(htmlTemplate, skipLine);
  getline(htmlTemplate, copyLine);

  while (copyLine != skipLine) {
    blogHtml << copyLine << endl;
    getline(htmlTemplate, copyLine);
  }

  string postTitle, postDate, BegEnd, lineBreak;

  getline(blogText, lineBreak);
  getline(blogText, BegEnd);
  getline(blogText, postTitle);
  getline(blogText, postDate);

  blogHtml << "<h2>" << postTitle << "</h2>\n";
  blogHtml << "<h2>" << postDate << "</h2>\n" << "</div>";

  getline(blogText, copyLine);
  blogHtml << "<p>\n";

  getline(blogText, copyLine);

  while (copyLine != BegEnd){
    if (copyLine == lineBreak) {
      blogHtml << "</p>\n" << "<p>\n";
    }

    else {
      blogHtml << copyLine << endl;
    }

    getline(blogText, copyLine);
  }

  blogHtml << "</p>\n";

  getline(htmlTemplate, copyLine);
  while (copyLine != skipLine) {
    blogHtml << copyLine << endl;
    getline(htmlTemplate, copyLine);
  }

  blogHtml << "<li>" << dateText << "</li>\n";

  getline(htmlTemplate, copyLine);
  while(copyLine != skipLine) {
    blogHtml << copyLine << endl;
    getline(htmlTemplate, copyLine);
  }

  blogText.close();
  htmlTemplate.close();
  blogHtml.close();

  return 0;
}
