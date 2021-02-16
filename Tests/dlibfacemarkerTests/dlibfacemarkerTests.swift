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
		let size = 68
		let landmarks = [XY](repeating: XY(), count: size)
		let total = landmarks.withUnsafeBufferPointer {
			dlib_facemarker_run(lib, "/tmp/face.png", $0.baseAddress, UInt(size))
		}
		XCTAssertEqual(total, UInt(size))
		print(landmarks)
		dlib_facemarker_close(lib)
	}

	static var allTests = [
		("testExample", testExample),
	]
}
