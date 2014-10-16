import bb.cascades 1.3

Container {
    property bool haveFocus: false
    property int horizontalMinimalSwipeInDU: 36
    property int verticalMinimalSwipeInDU: 10
    signal swipeUp
    signal swipeDown
    signal swipeRight
    signal swipeLeft
    ScrollView {                
        id: mainScrollView
        scrollRole: haveFocus ? ScrollRole.Main : ScrollRole.None
        scrollViewProperties.scrollMode: ScrollMode.Both
        property int startX
        property int stopX
        property int startY
        property int stopY
        property int minimumDistanceX: ui.du(horizontalMinimalSwipeInDU)
        property int minimumDistanceY: ui.du(verticalMinimalSwipeInDU)
        eventHandlers: [
            TouchKeyboardHandler {
                id: touchKeyboard
                onTouch: {
                    if (event.touchType == TouchType.Down) {
                        mainScrollView.startX = event.screenX
                        mainScrollView.startY = event.screenY
                        return
                    }
                    if (event.touchType == TouchType.Up) {
                        mainScrollView.stopX = event.screenX
                        mainScrollView.stopY = event.screenY

                        var distanceX = mainScrollView.stopX - mainScrollView.startX
                        var distanceY = mainScrollView.stopY - mainScrollView.startY
                        
                        if (distanceX > mainScrollView.minimumDistanceX) {
                            console.log("Swiped right " + distanceX)
                            // Emit swipeRight signal
                            swipeRight()
                        } else {
                            if (distanceX < (0 - mainScrollView.minimumDistanceX)) {
                                console.log("Swiped left " + distanceX)
                                // Emit swipeLeft signal
                                swipeLeft()
                            } else {
                                console.log("Distance too short for horizontal swipe... " + distanceX)
                            }
                        }
                        
                        if (distanceY > mainScrollView.minimumDistanceY) {
                            console.log("Swiped down " + distanceY)
                            // Emit swipeDown signal
                            swipeDown()
                        } else {
                            if (distanceY < (0 - mainScrollView.minimumDistanceY)) {
                                console.log("Swiped up " + distanceY)
                                // Emit swipeUp signal
                                swipeUp()
                            } else {
                                console.log("Distance too short for vertical swipe... " + distanceY)
                            }
                        }

                        return
                    }
                }
            }
        ]
    }
}
