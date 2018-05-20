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
  ScrollView,
  TouchableOpacity,
  ActivityIndicator
} from 'react-native';
import NetworkManager from 'react-native-ibgx-network-manager';

const instructions = Platform.select({
  ios: 'Press Cmd+R to reload,\n' + 'Cmd+D or shake for dev menu',
  android:
    'Double tap R on your keyboard to reload,\n' +
    'Shake or press menu button for dev menu'
});

export default class App extends Component {
  constructor() {
    super();
    this.state = {
      error: null,
      list: [],
      isLoading: false
    };
  }

  componentDidMount() {
    this.getRequest();
  }

  render() {
    if (this.state.isLoading) {
      return (
        <View style={styles.loadingContainer}>
          <ActivityIndicator />
        </View>
      );
    }

    return (
      <View style={styles.container}>
        {!this.state.error && (
          <ScrollView style={styles.listContainer}>
            {this.state.list.map((item, i) => (
              <View key={i} style={styles.itemContainer}>
                <Text>{item.title}</Text>
                <View style={styles.separator} />
              </View>
            ))}
          </ScrollView>
        )}
        {!this.state.error && (
          <View style={styles.errorContainer}>
            <Text>{this.state.error}</Text>
            <TouchableOpacity onPress={() => this.getRequest()}>
              <Text>Try Again!</Text>
            </TouchableOpacity>
          </View>
        )}
      </View>
    );
  }

  getRequest() {
    this.setState({ isLoading: true });
    NetworkManager.get(
      'https://www.propertyfinder.ae/mobileapi?page=0&order=pd',
      (error, res) => {
        if (error === null) {
          this.setState({ error, isLoading: false });
        }
        // alert(JSON.stringify(res.res[0]))
        this.setState({ list: res.res, isLoading: false, error: null });
      }
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#F5FCFF'
  },
  listContainer: {
    marginTop: 30
  },
  itemContainer: {
    padding: 20
  },
  separator: {
    height: StyleSheet.hairlineWidth,
    width: '100%',
    backgroundColor: 'grey',
    marginTop: 20
  },
  loadingContainer: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center'
  },
  errorContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center'
  }
});
