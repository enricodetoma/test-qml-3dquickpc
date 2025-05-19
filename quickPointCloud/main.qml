import QtQuick
import QtQuick.Controls
import QtQuick3D
import QtQuick3D.Helpers

import Example 1.0

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Stack")

    View3D {
        anchors.fill: parent
        environment: SceneEnvironment {
            lightProbe: Texture {
                source: "imageTesto.hdr"
            }
            backgroundMode: SceneEnvironment.SkyBox
        }

        PerspectiveCamera {
            id: camera
            z: 300
        }

        DirectionalLight {
            eulerRotation.x: -30
        }

        Model {
            geometry: CustomGeometry {
                count: 10000000
            }
            materials: PrincipledMaterial {
                pointSize: 10
            }
        }
    }

    WasdController {
        controlledObject: camera
    }
}
