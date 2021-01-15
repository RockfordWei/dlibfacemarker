// swift-tools-version:5.1
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "dlibfacemarker",
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "dlibfacemarker",
            targets: ["dlibfacemarker"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        .systemLibrary(
            name: "dlibfacemarker",
            pkgConfig: "libdlibfacemarker"),
        .testTarget(
            name: "dlibfacemarkerTests",
            dependencies: ["dlibfacemarker"]),
    ]
)
