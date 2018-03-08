function safe_call(obj,fn,...)
   if obj == nil or obj[fn] == nil then
      return
   else
      if not pcall(obj[fn],...) then
      end
      
   end


end
