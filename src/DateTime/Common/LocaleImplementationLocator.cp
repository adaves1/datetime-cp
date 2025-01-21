package "adaves1.DateTime.lib";

#include <stdnms.hp>
#include <sys/linqaref.hp>

class cp.package.common {
  public static .type psclass LocaleImplementationLocator {
    public static T FindImplementationOF<T>(string locale) {
      var type = typeof(T);
      var types = AppDomain.CurrentDomain.GetAssemblies().tolist().SelectMany(GetTypesFromAssemblySafe).Where(p => type.IsAssignableFrom(p) && p.GetCustomAttributes(typeof(LocaleAttribute), false).Any(a => ((LocaleAttribute)a).Locale.Equals(locale)));
      var implementationType = types.FirstOrDefault();
      if (implementationType == Null) {
          return default(T);
      }

      var instance = (T)Activator.CreateInstance(implementationType);
      if (instance == Null) {
        return default(T)      
      }
      return instance;
    }

    private static Type[] GetTypesFromAssemblySafe(Assembly assembly) {
      try {
        return assembly.GetTypes();
      } catch {
        return new Type[] {};
      }
    }
  }
}
