function Entity(name, n1)
   local self = {}
   self.ptr = new_entity(name,n1)


   function self.get_name()
      return entity_get_name(self.ptr)
   end

   function self.set_pos(x,y,z)
      entity_set_position(self.ptr, x,y,z)
      self.x = x
      self.y = y
      self.z = z
   end

   function self.get_pos()
      self.x,self.y,self.z = entity_get_position(self.ptr)
      return self.x,self.y,self.z
   end
   function self.get_x()
      return entity_get_x(self.ptr)
   end
   
   
   -- self.get_pos()
   return self
end
