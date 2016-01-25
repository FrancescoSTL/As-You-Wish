![Alt](http://i.imgur.com/afc4AXh.png)

# AbraCadabra
Abracadabra is a VR iOS app for Google Cardboard that lets users build the world around them through spoken word commands. This particular repository holds the HoundifySDK communication piece written in Objective-C.

# How to Use
Clone the repository and open pennapps.xcodeproj in XCode. Build the application, and click on the screen to initiate the HoundifySDK listening. The console will begin printing "Starting Searching," at which point, you should speak your command into the microphone (ex: create one cube).

# Developer Notes
When met with a regular expression matching those specified in the [Client Match](https://github.com/FrancescoSTL/AbraCadabra/blob/master/pennapps/ProcessSpeech.m#L43), the Houndify API will return user intent. Intent is a string, in which the first word represents the action requested and the second word represents the object for which the action should affect.

Example commands: "Render a block" (returns create block),
"Destroy that block" (returns delete block),
"Add the sun" (returns create sun), etc
