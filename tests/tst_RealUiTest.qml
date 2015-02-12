/**
 * Tests that operate on the UI level. They expect window to be shown. All the mouseClick-like test utilities can be used then
 */
import QtQuick 2.0
import QtTest 1.0
import Sailfish.Silica 1.0

//import "../src/qml/pages"
import "../harbour-sleepfollower-pro-sailfish/qml/pages"


// Putting TestCase into the full app structure to test UI interactions and probably page transitions too
ApplicationWindow {
    id: wholeApp
    initialPage: SleepFollower {
        id: uiSleepFollower
    }

    TestCase {
        name: "test on the very UI level"
        when: windowShown

        function test_goToBed() {
            uiSleepFollower._goToBedMenuAction.clicked(null);
            compare(uiSleepFollower._sleepStore.inBed,true,"inBed should be true");
            compare(uiSleepFollower._status.text,"In Bed")
        }

        function test_getUp() {
            uiSleepFollower._sleepStore.inBed=true;
            uiSleepFollower._getUpMenuAction.clicked(null);
            compare(uiSleepFollower._sleepStore.inBed,false,"inBed should be false");
            compare(uiSleepFollower._status.text,"Up")
        }

    }

}

