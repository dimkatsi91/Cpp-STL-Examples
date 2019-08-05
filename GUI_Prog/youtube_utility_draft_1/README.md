> <h2><strong>Youtube-dl GUI Utility</strong></h2> 

<h5>Title  : Youtube-dl GUI</h5>

<h5>Author : Dimos Katsimardos</h5>

<h5>Date   : August 03, 2019</h5>

<h5>Dev Environment  : Qt Creator 4.9.2 Open Source Community Edition</h5>

<h5>Work Environment : Ubuntu Linux 18.04 LTS</h5>

<h5>GUI Version      : First Draft, v1.0.1

-------------------------------------------------------------------------------------------------------------------------------

> #### __Information__ ####

<h5> This GUI is supported under next prerequisites :</h5>

* Linux | Mostly Debian-based Distros
* ffmpeg or similar utility needs to be installed for the mp3 download option
* youtube-dl program needs to be installed
* Qt Creator 4.9.2 is recommended to be installed in order to open this GUI
* After opening the main GUI window select the button in order to start the QDialog regarding Youtube-dl GUI
* Beta version, will be updated frequently for more functionality | still a working project


- [x] Example

* The starting window is appearing as soon the Qt Run button is pressed :

![Starting Window/Widget](https://github.com/dimkatsi91/Cpp-STL-Examples/blob/master/GUI_Prog/youtube_utility_draft_1/Photos/Start_Window.png)

<h7> Next, when the button 'Start Youtube-dl Utility' is pressed, the Main QDialog GUI is shown : </h7>
- [x] OPTIONS/SCENARIOS
  - Provide the youtube url
  - Provide the full path
  - Enter mp3 || mkv download option
  - Press PROCEED
  - If CANCEL button is pressed the QDialog window is closed and the main window is coming in ficus again to try again!
  - If INFO button is pressed a QMessage window appears with a small usage message.
  - If a path is not entered, then a Message Window appears and You should start again the application.
  - If a url is not entered, then a Message Window appears and You should start again the application too!
  - If the provided path does not exist, a Messsage Error Window appears & You should provide a valid path to try again!

![Youtube-dl Utility GUI](https://github.com/dimkatsi91/Cpp-STL-Examples/blob/master/GUI_Prog/youtube_utility_draft_1/Photos/The_Main_Dialog_Window.png)
