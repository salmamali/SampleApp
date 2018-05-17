
# react-native-instacapture

## Getting started

`$ npm install react-native-instacapture --save`

### Mostly automatic installation

`$ react-native link react-native-instacapture`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-instacapture` and add `RNInstacapture.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNInstacapture.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.reactlibrary.RNInstacapturePackage;` to the imports at the top of the file
  - Add `new RNInstacapturePackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-instacapture'
  	project(':react-native-instacapture').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-instacapture/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-instacapture')
  	```

#### Windows
[Read it! :D](https://github.com/ReactWindows/react-native)

1. In Visual Studio add the `RNInstacapture.sln` in `node_modules/react-native-instacapture/windows/RNInstacapture.sln` folder to their solution, reference from their app.
2. Open up your `MainPage.cs` app
  - Add `using Instacapture.RNInstacapture;` to the usings at the top of the file
  - Add `new RNInstacapturePackage()` to the `List<IReactPackage>` returned by the `Packages` method


## Usage
```javascript
import RNInstacapture from 'react-native-instacapture';

// TODO: What to do with the module?
RNInstacapture;
```
  