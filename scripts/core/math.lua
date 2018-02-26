function math.sign(x)
   if x >=0 then
      return 1
   else
      return -1
   end
end


function Vector3(x,y,z)
   local self = setmetatable({},{
	 __add = function(self,v)
	    local new_v = Vector3(self.x + v.x, self.y + v.y, self.z + v.z)
	    return new_v
	 end
   })

   self.x = x
   self.y = y

   return self
end
function Vector2(x,y)
   local self = setmetatable({},{
	 __add = function(self,v)
	    local new_v = Vector2(self.x + v.x, self.y + v.y)
	    return new_v
	 end
   })

   self.x = x
   self.y = y

   return self
end

