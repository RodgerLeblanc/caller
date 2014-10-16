import bb.cascades 1.3
import bb.system 1.2

Sheet {
    id: aboutSheet
    Page {
        titleBar: TitleBar {
            title: qsTr("About")
            acceptAction: ActionItem {
                title: qsTr("Ok")
                onTriggered: {
                    aboutSheet.close()
                }
            }
        }
        ScrollView {
            Container {
                topPadding: ui.du(3)
                leftPadding: topPadding
                rightPadding: topPadding
                bottomPadding: topPadding
                layout: DockLayout {}
                horizontalAlignment: HorizontalAlignment.Fill
                verticalAlignment: VerticalAlignment.Fill
                Container {
                    horizontalAlignment: HorizontalAlignment.Center
                    verticalAlignment: VerticalAlignment.Center
                    Label {
                        text: "This app adds CallerId support to Talk2Watch Pro and Free editions. It's provided as a free headless app, meaning that you only need to toggle the option ON, close the app and forget about it, it will work seemlessly.\n\nBenjamin Sliwa (Talk2Watch developer) already stated that CallerId will be supported natively in the next Talk2Watch Pro big update, but until then, you can use this app.\n\nTalk2Watch Free users only : Go to Talk2Watch Settings -> Network -> Udp Server -> Toggle OFF then ON."
                        multiline: true
                        textStyle.base: SystemDefaults.TextStyles.TitleText
                    }
                    Label {
                        horizontalAlignment: HorizontalAlignment.Center
                        text: Application.applicationName + " " + Application.applicationVersion
                        textStyle.base: SystemDefaults.TextStyles.BigText
                    }
                    Label {
                        horizontalAlignment: HorizontalAlignment.Center
                        text: "<html><a href=\"http://bit.ly/1w7LUfm\">Donate</a></html>"
                        textStyle.base: SystemDefaults.TextStyles.BodyText
                    }
                    Label {
                        horizontalAlignment: HorizontalAlignment.Center
                        text: "<html>\n\nThanks to <a href=\"http://myersdesign.com\">Liz Myers</a> for app icon</html>"
                        multiline: true
                        textStyle.base: SystemDefaults.TextStyles.BodyText
                    }
                }
            }
        }
    }
}
