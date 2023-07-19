import 'package:first_app/gradient_container.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(const MaterialApp(
    home: Scaffold(
      body: GradientContainer(
        from: Color.fromARGB(255, 28, 5, 92),
        to: Color.fromARGB(255, 67, 50, 97))
    ),
  ));
}
