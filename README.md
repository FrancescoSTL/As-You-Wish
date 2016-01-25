# AbraCadabra
Abracadabra is a VR iOS app for Google Cardboard that lets users build the world around them through spoken word commands. This particular repository holds the HoundifySDK communication piece written in C#.

# Developer Notes
Houndify SDK for speech recognition. When met with a regular expression matching those specified in the [Client Match](https://github.com/FrancescoSTL/AbraCadabra/blob/master/pennapps/ProcessSpeech.m#L43), the Houndify API will return user intent. Intent is a string, in which the first word represents the action requested and the second word represents the object for which the action should affect.

Example commands: "Render a block" (returns create block),
"Destroy that block" (returns delete block),
"Add the sun" (returns create sun), etc
