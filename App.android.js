/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from 'react';
import {
  Platform,
  StyleSheet,
  Text,
  View,
  TouchableOpacity,
  Image,
  Dimensions,
  TextInput,
  Keyboard,
  ScrollView
} from 'react-native';
import Instacapture from 'react-native-instacapture';

const width = Dimensions.get('window').width;

export default class App extends Component {
  constructor() {
    super();
    this.state = {
      image: null
    };
  }

  render() {
    return (
      <ScrollView keyboardShouldPersistTaps='handled' style={styles.scrollContainer}>
        <View style={styles.container}>
          <Text style={styles.welcome}>Welcome to Instacapture!</Text>
          <TextInput
            placeholder="Type a text and take a screenshot!"
            style={styles.textInput}
          />
          <TouchableOpacity onPress={() => this.capture()} style={styles.button}>
            <Text style={styles.buttonText}>Take Screenshot</Text>
          </TouchableOpacity>
          {this.state.image && (
            <View>
              <Text style={styles.imageText}>Your image</Text>
              <Image
                source={{ uri: `data:image/png;base64,${this.state.image}` }}
                style={styles.image}
                resizeMode="contain"
              />
            </View>
          )}
        </View>
      </ScrollView>
    );
  }

  async capture() {
    Keyboard.dismiss();

    try {
      const png = await Instacapture.capture();

      this.setState({ image: png });
    } catch (error) {
      alert('Cannot take screenshot! Something went wrong!');
      console.log(error);
    }
  }
}

const styles = StyleSheet.create({
  scrollContainer: {
    flex: 1,
    backgroundColor: '#F5FCFF'
  },
  container: {
    flex: 1,
    alignItems: 'center'
  },
  welcome: {
    fontSize: 20,
    textAlign: 'center',
    margin: 10,
    marginTop: 30
  },
  instructions: {
    textAlign: 'center',
    color: '#333333',
    marginBottom: 5
  },
  imageText: {
    fontSize: 14,
    color: 'black',
    marginTop: 20,
    marginBottom: 10
  },
  image: {
    width: width - 20,
    height: 500,
    borderColor: '#293821',
    borderWidth: 1,
    marginBottom: 20
  },
  button: {
    backgroundColor: '#237481',
    padding: 15,
    borderRadius: 5,
    marginTop: 20
  },
  buttonText: {
    color: 'white',
    fontSize: 16
  },
  textInput: {
    width: width - 20
  }
});
