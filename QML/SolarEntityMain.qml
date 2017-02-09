import Qt3D.Core 2.0
import Qt3D.Extras 2.0
import SolarSystem 1.0

Entity {
    id: rootEntity

    SolarEntity {
        id: solarSystem

        // Skybox
        SkyboxEntity {
            baseName: "qrc:/Resources/Skybox/stars"
            extension: ".webp"
        }
    }
}
