/*PROGRAMA PARA CONTROLAR EL ROBOT MEDIANTE BLUETOOTH
 * USANDO FUNCIONES DE USUARIO
 */

char dato;
int vd;
int vi;
int a;
int b;
void setup( ) {
  //configuramos E/S digitales del robot
  Serial.begin(9600);
 
  pinMode(8,OUTPUT);  //  Motor derecha
  pinMode(9,OUTPUT);  //
  
  pinMode(6,OUTPUT);  //  Motor izquierda
  pinMode(7,OUTPUT);  // 

  pinMode(12,OUTPUT); // buzzer
  
}

void loop( ) {

  if (Serial.available() > 0) {
    dato = Serial.read();
    Serial.println(dato);
      switch (dato) {

      case ('F'): {    
          //robot movimiento adelante
          movimiento(1,0,255,255);
          break;
        }
     
      case ('B'): {    
          //robot movimiento atrás
          movimiento (0,1,255,255);
          break;          
       }
      
      case ('L'): {       
          //robot movimiento izquierda
          movimiento (1,0,0,255); 
          break;
        }
      
      case ('R'): {     
          //robot movimiento derecha
          movimiento(1,0,255,0);
          break;
        }
      case ('G'): {    
          //robot movimiento adelante y izquierda
          movimiento (1,0,85,255);
          break;
        }
      case ('I'): {    
          //robot movimiento adelante y derecha
          movimiento(1,0,255,85);
          break;
        }
      case ('H'): {    
          //robot movimiento atras y izquierda
          movimiento (0,1,85,255);
          break;
        }
      case ('J'): {    
          //robot movimiento atras y derecha
           movimiento(0,1,255,85); 
          break;
        }
        
      case ('S'): {     
          //paro motores
          analogWrite (11,0);
          analogWrite (10,0); 
          break;
        }
      case ('V'): { 
        //pito    
          digitalWrite(12,1);
          delay(50);
          digitalWrite(12,0); 
          break;
        }
     case ('v'): {
       //pito   
          digitalWrite(12,1);
          delay(50);
          digitalWrite(12,0);
          break;
       }
      case ('X'): { 
        //giro
          analogWrite (11,255);
          digitalWrite (8,1);
          digitalWrite (9,0);
          analogWrite (10,255);
          digitalWrite (6,1);
          digitalWrite (7,0);
          delay(2000); 
          break;
       }
       case ('x'): { 
         //giro
          analogWrite (11,255);
          digitalWrite (8,0);
          digitalWrite (9,1);
          analogWrite (10,255);
          digitalWrite (6,0);
          digitalWrite (7,1);
          delay(2000);
          break;
       }
    }
  }
}
void movimiento (int a,int b,int vd,int vi){
  
          analogWrite (11,vd);
          digitalWrite (8,a);
          digitalWrite (9,b);
          analogWrite (10,vi);
          digitalWrite (6,b);
          digitalWrite (7,a);
  
}

