#!/bin/bash

# Script for running tests. That's for specifying just one argument in QtCreator's configuration
/usr/bin/tst-harbour-sleepfollower-pro-sailfish -input /usr/share/tst-harbour-sleepfollower-pro-sailfish

# When you'll get some QML components in the main app, you'll need to import them to the test run
# /usr/bin/tst-harbour-sleepfollower-pro-sailfish -input /usr/share/tst-harbour-sleepfollower-pro-sailfish -import /usr/share/harbour-sleepfollower-pro-sailfish/qml/components