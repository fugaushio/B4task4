#ifndef POISSON_H
#define POISSON_H

#include <string>
#include <vector>

class Poisson {
public:
    Poisson(const std::string& path);//コンストラクタの宣言

    void poisson();//メンバ関数
    
    void read_node();//nodeの情報を読み込む
    void output_node();//(確認用)
    void analyze_node();//読み込んだ情報からdx,dy,Lx,Lyを出す
    void makeMatrix();//形状と境界条件から係数行列とベクトルを作る
    void solver();//連立方程式を解く
    void output_phi();//出力(確認用)
    void showMap();//描画

private:
    //非公開メンバ
    std::string node_path;
    
    std::vector<std::pair<double, double>> nodes;// ノード情報（x, y）を格納

    double dx, dy ;
    double Lx, Ly ;
 
    std::vector<std::vector<double>> Matrix;
    std::vector<double> Vector;
    std::vector<double> Phi;
};

#endif // GREETER_H
