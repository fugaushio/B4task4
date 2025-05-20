#include <iostream>
#include "Poisson.h"

void  Poisson::poisson() {//メンバ関数をまとめた

    this->read_node();      //nodeの情報を読み込む
    //this->output_node();
    this->analyze_node();   //読み込んだ情報からdx,dy,Lx,Lyを出す
    this->makeMatrix();     //形状と境界条件から係数行列とベクトルを作る
    this->solver();         //連立方程式を解く
    this->output_phi();
    //this->showMap();        //描画

}