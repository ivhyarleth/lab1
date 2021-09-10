#pragma once

#include "SpatialBase.h"
#include <map>
#include <vector>

namespace utec {
namespace spatial {

/**
 * BasicSpatial implementation
 */
template <typename Point>
class BasicSpatial : public SpatialBase<Point> {
 private:
  //std::map<int,std::vector<int>> puntos; 
  std::vector<Point> points;
 public:
  BasicSpatial() {};

  void insert(const Point& new_point) override {
    //puntos.insert_or_assign({new_point.get(0),new_point.get(1)});
    points.push_back(new_point);
  }

  double distance(Point one, Point two){
    double distancia = sqrt(pow(one.get(0)-two.get(0),2) + pow(one.get(1)-two.get(1),2));
    return distancia;
  }

  // El punto de referencia no necesariamente es parte del dataset
  Point nearest_neighbor(const Point& reference) override { 
    std::map<double, Point> distancias;
    for(auto iter=points.begin(); iter!=points.end(); iter++){
      distancias.insert({distance(reference,*iter),*iter});
    }
    
    Point vecino = distancias.begin()->second;
    return vecino;   
    //return Point({0,0});
  }
};

}  // namespace spatial
}  // namespace utec
