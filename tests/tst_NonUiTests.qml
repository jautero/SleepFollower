/**
 * Tests that operate with instantiated QML components, yet don't really need Application Window to be created
 * That will produce a lot of warnings, UI utilities such as mouseClick won't work, but the test code becomes simpler
 * and runs faster
 * And if you do want to operate on the muse level, you can get almost there via e.g. triggering clicked(null) signal handler
 *
 */

import QtQuick 2.0
import QtTest 1.0

// At runtime proper folder to import is "../harbour-sleepfollower-pro-sailfish/qml/pages"
// You can check the main app deployment folder from it's DEPLOYMENT_PATH qmake var in .pro
// Faster to check from .spec file, however

// At design-time I uncomment import "../src/qml/pages" so that QtCreator auto-completion would work

//import "../src/qml/pages"
import "../harbour-sleepfollower-pro-sailfish/qml/pages"

TestCase {
    name: "inBedTest"
    SleepFollower {
        id: testFollower
    }

    function test_defaultValue() {
        compare(testFollower._sleepStore.inBed,false,"default value should be false");
    }
    function test_setTrue() {
        testFollower._sleepStore.inBed = true;
        compare(testFollower._sleepStore.inBed,true,"value should be set to true");
    }
    function test_setFalse() {
        testFollower._sleepStore.inBed = false;
        compare(testFollower._sleepStore.inBed,false,"value should be set to false");
    }
}


