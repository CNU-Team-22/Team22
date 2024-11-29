import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp()); //runApp 앱시작하기
}


class MyApp extends StatelessWidget {  //stless  //앱 메인페이지 만드는 법
  const MyApp({super.key});
  @override
  Widget build(BuildContext context) {

    return MaterialApp(  //여기가 실질적으로 코딩할 자리.
      home: Scaffold(
        appBar: AppBar(
            centerTitle: true,
            backgroundColor: Colors.amber,
            title: Text('태욱이의 첫 앱')
        ),
        body: Container(
            child:
            Text('안녕 난 태욱이야.'),
        ),
        bottomNavigationBar: BottomAppBar(
          child: SizedBox(
            height: 70,
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
              Icon(Icons.phone),
              Icon(Icons.message),
              Icon(Icons.contact_page),
              ],
            )
          ),
        ),
      )
    );
  }
}

