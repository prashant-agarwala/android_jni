//#include<vector>

#include "apayi.h"
#include "apayi_exception.h"
#include<jni.h>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <exception>
#include <fstream>


using namespace std;
using namespace apayi;
extern "C" {
 jstring Java_com_example_virtual_myapp2_MainActivity_stringFromApayi(
        JNIEnv * env, jobject thiz) {
     try {
         SECRET_KEY = "RGl7DwXio30HxRhIwAuJ6OC9f1f1jqWHKLquUPxGja7sQbbpETGWOSX4vybyKtZ+cQQZjjC7yJn7iMNJNXtyRw==";
         CLIENT_ID = "64f61699-1bf6-40af-bc4e-353775f51b1d";
         using apayi::payment;
         std::vector <payment> payments = get_payments();

         std::string payment_id = payments[0].id();

         jstring str = env->NewStringUTF((const char *) payment_id.c_str());

         return str;
     }
     catch(apayi_business_exception &e)
     {

         jclass jcls = env->FindClass("com/example/virtual/myapp2/ApayiException");
         jboolean flag = env->ExceptionCheck();
         if (flag) {
             env->ExceptionClear();
             /* code to handle exception */
         }
         env->ThrowNew(jcls, e.what());
         //return;

        // jstring str = env->NewStringUTF((const char *) e.what()   );
        // return str ;
     }
     catch(apayi_exception &e)
     {
         jclass jcls = env->FindClass("java/lang/Exception");
         jboolean flag = env->ExceptionCheck();
         if (flag) {
             env->ExceptionClear();
             /* code to handle exception */
         }
         env->ThrowNew(jcls, e.what());
        // return;
     }
     catch(std::exception &e)
     {
         jclass jcls = env->FindClass("java/lang/Exception");
         jboolean flag = env->ExceptionCheck();
         if (flag) {
             env->ExceptionClear();
             /* code to handle exception */
         }
         env->ThrowNew(jcls, e.what());
       //  return;
     }

}
}