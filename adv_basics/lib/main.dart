import 'package:adv_basics/start_screen.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(MaterialApp(
    home: Scaffold(
      body:  Container(
        decoration: const BoxDecoration(
          gradient: LinearGradient(
            begin: Alignment.topLeft, 
            end:Alignment.bottomRight,
            colors: [Color.fromRGBO(21, 11, 37, 1), Colors.deepPurple]
        )),
        child: const StartScreen()
        )
    )
  ));
}