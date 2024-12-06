import 'package:flutter/material.dart';

void main() {
  runApp(
      MaterialApp(
          home: MyApp()
      )
  ); //runApp 앱시작하기
}

class MyApp extends StatefulWidget {  //stless  //앱 메인페이지 만드는 법
  MyApp({Key? key}) : super(key:key);

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  var name = ['22김태욱', '22박재연', '22이현우', '22정정훈'];
  var like = [0,0,0,0];

  addOne(int i){
    setState(() {
      like[i]++;
    });
  }

  @override
  Widget build(BuildContext context) {

    return Scaffold(
        floatingActionButton: FloatingActionButton(
          onPressed: (){
            showDialog(context: context, builder: (context){
              return DialogUI(addOne : addOne);
            });
          },
        ),

        appBar: AppBar(
          backgroundColor: Colors.blue,
          title: Text("누가 가장 인기가 많을까요?"),
        ),

        body: ListView.builder(
          itemCount: 4,
          itemBuilder: (context, i){
            return ListTile(
              leading: Text(like[i].toString()),
              title: Text(name[i]),
            );
          },
        )
    );
  }
}

class DialogUI extends StatelessWidget {
  DialogUI({Key? key, this.addOne}):super(key:key);
  final addOne;

  @override
  Widget build(BuildContext context) {
    return Dialog(
        child: SizedBox(
            width: 412, height: 90,
            child: Column(
              children: [
                Text("누구를 투표하실 건가요?"),
                Row(
                  children: [
                    ElevatedButton(
                        onPressed: (){
                          addOne(0);
                          Navigator.pop(context);
                        },
                        child: Text("22김태욱")
                    ),
                    ElevatedButton(
                        onPressed: (){
                          addOne(1);
                          Navigator.pop(context);
                        },
                        child: Text("22박재연")
                    ),
                    ElevatedButton(
                        onPressed: (){
                          addOne(2);
                          Navigator.pop(context);
                        },
                        child: Text("22이현우")
                    ),
                    ElevatedButton(
                        onPressed: (){
                          addOne(3);
                          Navigator.pop(context);
                        },
                        child: Text("22정정훈")
                    ),
                  ],
                ),
                TextButton(
                  child: Text('취소'),
                  onPressed: (){Navigator.pop(context);}
                ),
              ],
            )
        )
    );
  }
}
