import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.Silica 1.0
import fi.iki.jautero.sleepfollower 1.0

// Just a simple example to demo both property binding and doing something via pulley menu action
// to provide a sample of Sailfish-specific UI testing
Page {
    id: page

    // These are to be filled by whoever instantiates the page
    // Or can be left clean e.g. for testing scripts who don't care about the version numbers
    property string version: ""
    property string buildNum: ""
    SleepStore {
        id: sleepStore
    }

    // Exposing properties for testing. In real app you might like to hide it behind a single interface
    // e.g. via "property variant internals" and then put a QtObject with the individual properties to it
    // @TODO: implement exposing via single internals property

    property alias _goToBedMenuAction: goToBedMenuAction
    property alias _getUpMenuAction: getUpMenuAction
    property alias _sleepStore: sleepStore
    property alias _status: status

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaFlickable {
        anchors.fill: parent

        // PullDownMenu and PushUpMenu must be declared in SilicaFlickable, SilicaListView or SilicaGridView
        PullDownMenu {
            id: pullDownMenu
            MenuItem {
                id: goToBedMenuAction
                text: "Go to bed"
                onClicked: {
                    sleepStore.inBed = true;
                }
            }
        }
        
        // Tell SilicaFlickable the height of its content.
        contentHeight: childrenRect.height

        // Place our content in a Column.  The PageHeader is always placed at the top
        // of the page, followed by our content.
        Column {
            anchors.fill: parent
            anchors.margins: Theme.paddingLarge
            spacing: Theme.paddingLarge
            PageHeader {
                title: "Sleep Follower"
            }
            Label {
                id: status
                text: sleepStore.inBed ? "In Bed" : "Up"
            }
        }
        PushUpMenu {
            id: pushUpMenu
            MenuItem {
                id: getUpMenuAction
                text: "Get up"
                onClicked: {
                    sleepStore.inBed = false;
                }
            }
        }
    }

}
