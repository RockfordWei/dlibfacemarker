import XCTest
import Foundation
@testable import dlibfacemarker

struct XY {
	var x: UInt16 = 0
	var y: UInt16 = 0
}
final class dlibfacemarkerTests: XCTestCase {
	func testExample() {
		// This is an example of a functional test case.
		// Use XCTAssert and related functions to verify your tests produce the correct
		// results.
		let lib = dlib_facemarker_load("/tmp/shape_predictor_68_face_landmarks.dat")
		XCTAssertNotNil(lib)

		let buffer = dlib_facemarker_run(lib, "/tmp/face.png", 256)
		XCTAssertNotNil(buffer)
		if let pointer = buffer?.assumingMemoryBound(to: XY.self) {
			for i in 0..<68 {
				let p = pointer.advanced(by: i).pointee
				print(i, p.x, p .y)
			}
		}
		free(buffer)
		dlib_facemarker_close(lib)
	}

	static var allTests = [
		("testExample", testExample),
	]
}
