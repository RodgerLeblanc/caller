/*
 * Copyright (c) 2013-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import bb.cascades 1.3
import bb.system 1.2
import bb.device 1.3

Page {
    property bool sendPhoneNumberToPebble: _settings.value("send", false)
    property string isPassport: thisDevice.modelName == "Passport"
    
    onCreationCompleted: {
        if (isPassport)
            systemToast.show()
    }
    
    Container {
        layout: DockLayout {}
        horizontalAlignment: HorizontalAlignment.Fill
        verticalAlignment: VerticalAlignment.Fill
        Container {
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            Container {
                layout: StackLayout {
                    orientation: LayoutOrientation.LeftToRight
                }
                Label {
                    text: "Send phone number to Pebble"
                }
                ToggleButton {
                    id: toggleButton
                    checked: sendPhoneNumberToPebble
                    onCheckedChanged: {
                        _settings.setValue("send", checked)
                    }
                }
            }
        }
        KeyboardListener {
            haveFocus: true
            onSwipeLeft: toggleButton.setChecked(false)
            onSwipeRight: toggleButton.setChecked(true)
        }
    }

    Menu.definition: MenuDefinition {
        settingsAction: [
            SettingsActionItem {
                ActionBar.placement: ActionBarPlacement.OnBar
                onTriggered: {
                    settingsSheet.open()
                }
            }
        ]
        
        actions: [
            ActionItem {
                title: qsTr("About")
                ActionBar.placement: ActionBarPlacement.OnBar
                imageSource: "asset:///images/ic_info.png"
                onTriggered: {
                    aboutSheet.open()
                }
            },
            ActionItem {
                title: qsTr("More apps")
                ActionBar.placement: ActionBarPlacement.OnBar
                imageSource: "asset:///images/ic_share.png"
                onTriggered: {
                    invoke.trigger("bb.action.OPEN");
                }
            }
]      
    } // end of MenuDefinition
    
    attachedObjects: [
        AboutSheet {
            id: aboutSheet
        },
        SettingsSheet {
            id: settingsSheet
        },
        ComponentDefinition {
            id: menu
        },
        Invocation {
            id: invoke
            query {
                invokeTargetId: "sys.appworld"
                uri: "appworld://vendor/70290"
            }
        },
        SystemToast {
            id: systemToast
            body: "This toggle can be controlled with your touch enabled keyboard!"
            position: SystemUiPosition.TopCenter
        },
        HardwareInfo {
            id: thisDevice
        }
    ]
}
