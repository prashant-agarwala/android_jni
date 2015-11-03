Porting C++ Library to Android
==============================

References :
http://kvurd.com/blog/compiling-a-cpp-library-for-android-with-android-studio/

Setup :
Android Studio v1.4, NDK release 10, target SDK version of 14. Ubuntu (Linux-x86_64 was used).

Environment Variables :
Download Android NDK in the given path
NDK = /home/administrator/Android/Ndk
ANDROID_CC=$NDK/toolchains/arm-linux-androideabi-4.8/prebuilt/linux-x86_64/bin/arm-linux-androideabi-gcc
ANDROID_CXX=$NDK/toolchains/arm-linux-androideabi-4.8/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++


Overview :
These are the steps:

1. Compile your library for Android
	a. libapayi.a  Execute scons the apayi-cpp/android
	b. libcrypto.a (openssl) and libboost_system.a- Download android built libraries from online.
2. Create Android library project in Android Studio.
	a. Create android application project with no activity
	b. Replace  apply plugin: 'com.android.application' with  apply plugin: 'com.android.library' in app build.gradle
	c. Remove application id from android defaultConfig in app build.gradle
	d. Add <uses-permission android:name="android.permission.INTERNET"></uses-permission> in AndroidManifest.xml
3. Write the C/C++ wrapper for your library
	a. Create a prebuild\armeabi folder under project_root and copy your .a files  and include files there.
	b. Create jni folder under project_root and create Android.mk and Application.mk file to mention the dependencies. Also include your .cpp file containing Java-jni calls .
4. Write Java wrapper classes  
5. Run ndk-build
6. Configure gradle to package up your library
	a. Android Studio doesn't currently support NDK development so some gradle hacks are required. In a nutshell, the modifications copy and package up the .so file so that it is copied and installed with your app .
	b. In build.gradle add the following:
		task nativeLibsToJar(type: Zip, description: 'create a jar archive of the native libs') {
		    destinationDir file("$buildDir/native-libs")
		    baseName 'native-libs'
		    extension 'jar'
		    from fileTree(dir: 'libs', include: '**/*.so')
		    into 'lib/'
		}
		
		tasks.withType(JavaCompile) {
		    compileTask -> compileTask.dependsOn(nativeLibsToJar)
		} 
	c. Also add the following to the dependencies{...} section:
	compile fileTree(dir: "$buildDir/native-libs", include: 'native-libs.jar')
	
7. Do a clean build to find The output is .aar (android archive) file which will be distributed as library to the users.
8. Test from java - Create sample app and include the aar to test the library. 
