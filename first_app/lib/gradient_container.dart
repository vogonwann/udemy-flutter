import 'package:first_app/dice_roller.dart';
import 'package:flutter/material.dart';

const startAlignment = Alignment.topCenter;
const endAlignment = Alignment.bottomRight;

class GradientContainer extends StatelessWidget {
  const GradientContainer({super.key, required this.from, required this.to});
  const GradientContainer.purple(
      {super.key, this.from = Colors.deepPurple, this.to = Colors.indigo});

  final Color from;
  final Color to;

  @override
  Widget build(BuildContext context) {
    return Container(
      decoration: BoxDecoration(
        gradient: LinearGradient(
          colors: [from, to],
          begin: startAlignment,
          end: endAlignment,
        ),
      ),
      child: const Center(
        child: DiceRoller()
      )
    );
  }
}
