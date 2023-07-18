import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(
    home: Scaffold(
      body: Container(
        decoration: const BoxDecoration(
          gradient: LinearGradient(
            colors: [Color.fromARGB(255, 41, 16, 85), Color.fromARGB(255, 87, 63, 154)],
            begin: Alignment.topLeft,
            end: Alignment.bottomRight,
          ),
        ),
        child: const Center(
          child: Text(
              style: TextStyle(
                color: Colors.white,
                fontSize: 28,
              ),
              "Hello world!"),
        ),
      ),
    ),
  ));
}
